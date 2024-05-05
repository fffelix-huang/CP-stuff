current_shell=$SHELL

case $current_shell in
	/bin/bash)
		echo "[INFO] Setting up for bash environment..."

		echo "[INFO] Adding PATH to ~/.bashrc"
		echo "export FELIX_CP_LIBRARY_PATH=\"$(pwd)\"" >> ~/.bashrc
		echo "source \$FELIX_CP_LIBRARY_PATH/tools/cp-bash-commands.sh" >> ~/.bashrc

		echo "[INFO] Recompile ~/.zshrc"
		source ~/.bashrc
		;;
	/bin/zsh)
		echo "[INFO] Setting up for zsh environment..."

		echo "[INFO] Adding PATH to ~/.zshrc"
		echo "export FELIX_CP_LIBRARY_PATH=\"$(pwd)\"" >> ~/.zshrc
		echo "source \$FELIX_CP_LIBRARY_PATH/tools/cp-zsh-commands.zsh" >> ~/.zshrc

		echo "[INFO] Recompile ~/.zshrc"
		source ~/.zshrc
		;;
	*)
		echo "[INFO] Shell not supported :("
		exit
		;;
esac

echo "[INFO] Installed Successfully!"
