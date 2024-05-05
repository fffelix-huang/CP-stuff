---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import argparse\nimport os\nimport re\nimport sys\n\nfrom logging import\
    \ Logger, basicConfig, getLogger\nfrom pathlib import Path\nfrom typing import\
    \ List, Set\n\nlogger = getLogger(__name__)\n\nclass Expander:\n\theader_regex\
    \ = re.compile(r\"^\\s*#include\\s*[<\\\"]([^>\\\"]+)[>\\\"]\\s*$\")\n\t\n\tdef\
    \ __init__(self, lib_paths: List[Path]):\n\t\tself.lib_paths = lib_paths\n\t\t\
    self.included_headers = set()\n\n\tdef remove_ignored_lines(self, source: List[str])\
    \ -> List[str]:\n\t\tresult = []\n\n\t\tfor line in source:\n\t\t\tif line.strip()\
    \ == \"#pragma once\":\n\t\t\t\tcontinue\n\n\t\t\tif line.strip().startswith(\"\
    //\"):\n\t\t\t\tcontinue\n\n\t\t\tif line.find(\"debug\") != -1:\n\t\t\t\tcontinue\n\
    \n\t\t\tresult.append(line)\n\n\t\treturn result\n\n\t# Returns the full path\
    \ of the header, or None if doesn't exists.\n\tdef find_header(self, header: Path)\
    \ -> Path:\n\t\tfor lib_path in self.lib_paths:\n\t\t\tpath = lib_path / header\n\
    \n\t\t\tif path.exists() and path.is_file():\n\t\t\t\treturn path\n\n\t\treturn\
    \ None\t\n\n\tdef expand_header(self, header: Path, directory: Path) -> List[str]:\n\
    \t\tif header.resolve() in self.included_headers:\n\t\t\tlogger.info(f\"Already\
    \ included: {str(header)}\")\n\t\t\treturn []\n\t\t\n\t\tself.included_headers.add(header.resolve())\n\
    \t\tlogger.info(f\"Include: {str(header)}\")\n\n\t\tfile_path_str = str(header)\n\
    \t\tindex_of_last_slash = file_path_str.rfind('/')\n\t\tdirectory_path = Path(file_path_str[:index_of_last_slash])\n\
    \n\t\tsource = open(str(header)).read().splitlines()\n\t\tsource = self.remove_ignored_lines(source)\n\
    \n\t\tresult = []\n\n\t\tfor line in source:\n\t\t\tmatch = self.header_regex.match(line)\n\
    \n\t\t\tif match:\n\t\t\t\t# Case 1: Relative Path\n\t\t\t\tpath = directory /\
    \ match.group(1)\n\n\t\t\t\tif path.exists() and path.is_file():\n\t\t\t\t\tresult.extend(self.expand_header(header=path,\
    \ directory=path.parent))\n\t\t\t\t\tcontinue\n\n\t\t\t\t# Case 2: Included Path\n\
    \t\t\t\tpath = self.find_header(Path(match.group(1)))\n\n\t\t\t\tif path != None:\n\
    \t\t\t\t\tresult.extend(self.expand_header(header=path, directory=path.parent))\n\
    \t\t\t\t\tcontinue\n\n\t\t\t\t# Case 3: Standard Header File\n\t\t\t\tif Path(match.group(1))\
    \ in self.included_headers:\n\t\t\t\t\tcontinue;\n\n\t\t\t\tself.included_headers.add(Path(match.group(1)))\n\
    \n\t\t\tresult.append(line)\n\n\t\treturn result\n\n\tdef expand(self, source:\
    \ Path, directory: Path) -> List[str]:\n\t\tsource = open(str(source)).read().splitlines()\n\
    \t\tsource = self.remove_ignored_lines(source)\n\n\t\tresult = []\n\n\t\tfor line\
    \ in source:\n\t\t\tmatch = self.header_regex.match(line)\n\n\t\t\tif match:\n\
    \t\t\t\t# Case 1: Relative Path\n\t\t\t\tpath = directory / match.group(1)\n\n\
    \t\t\t\tif path.exists() and path.is_file():\n\t\t\t\t\tresult.extend(self.expand_header(header=path,\
    \ directory=path.parent))\n\t\t\t\t\tcontinue\n\n\t\t\t\t# Case 2: Included Path\n\
    \t\t\t\tpath = self.find_header(Path(match.group(1)))\n\n\t\t\t\tif path != None:\n\
    \t\t\t\t\tresult.extend(self.expand_header(header=path, directory=path.parent))\n\
    \t\t\t\t\tcontinue\n\n\t\t\t\t# Case 3: Standard Header File\n\t\t\t\tif Path(match.group(1))\
    \ in self.included_headers:\n\t\t\t\t\tcontinue;\n\n\t\t\t\tself.included_headers.add(Path(match.group(1)))\n\
    \n\t\t\tresult.append(line)\n\n\t\treturn result\n\t\nif __name__ == \"__main__\"\
    :\n\tbasicConfig(\n\t\tformat=\"%(asctime)s [%(levelname)s] %(message)s\",\n\t\
    \tdatefmt=\"%H:%M:%S\",\n\t\tlevel=os.getenv(\"LOG_LEVEL\", \"INFO\")\n\t)\n\n\
    \tparser = argparse.ArgumentParser(description=\n\t\t\"\"\"\n\t\t\texpander.py\
    \ performs the following functions:\n\t\t\t\n\t\t\t1. Removes ignored lines, or\
    \ any lines containing the word \"debug\".\n\t\t\t2. Merge all custom header files\
    \ into a single file.\n\t\t\"\"\"\n\t)\n\n\tparser.add_argument(\"source\", help=\"\
    Source code file\")\n\tparser.add_argument(\"destination\", help=\"Destination\
    \ file to store result\")\n\tparser.add_argument(\"--lib\", help=\"Path to your\
    \ custom library\")\n\tparser.add_argument(\"--author\", help=\"Author\")\n\n\t\
    opts = parser.parse_args()\n\n\tlib_paths = []\n\n\tif opts.lib:\n\t\tlib_paths.append(Path(opts.lib))\n\
    \n\texpander = Expander(lib_paths)\n\n\tsource = Path(opts.source)\n\toutput =\
    \ expander.expand(source=source, directory=Path.cwd())\n\n\tif opts.author:\n\t\
    \toutput.insert(0, \"// Author: \" + opts.author)\n\n\toutput = \"\\n\".join(output)\n\
    \n\twith open(opts.destination, \"w\") as f:\n\t\tf.write(output)\n\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/expander.py
layout: document
redirect_from:
- /library/tools/expander.py
- /library/tools/expander.py.html
title: tools/expander.py
---
