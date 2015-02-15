/*
 * Control application for 3D scanner
 */
#include "PhaseShiftSturcturedLight3DScanner.h"

string configFileName = "scannerConfig.xml";

int main()
{
	PhaseShiftStructuredLight3DScanner 3dScanner;
	3dScanner.scanObject();

	return 0;
}
