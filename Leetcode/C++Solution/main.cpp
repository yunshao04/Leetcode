#include "solution.h"
#include "203_RemoveLinkedListElements.cpp"

using namespace std;

int main() {
	slt::Solution *problemSolution = new RemoveLinkedListElements();
	problemSolution->buildSolution();
	delete problemSolution;
	system("pause");
	return 0;
}