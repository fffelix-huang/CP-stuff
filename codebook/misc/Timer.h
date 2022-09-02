const clock_t startTime = clock();
inline double getCurrentTime() {
	return (double) (clock() - startTime) / CLOCKS_PER_SEC;
}
