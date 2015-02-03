// executes 3D scanning pipeline
#include "PhaseShiftSturcturedLight3DScanner.h"


void PhaseShiftStructuredLight3DScaner::scanObject()
{

	systemCalibrator.calibrate();
	patternGenerator.generate();
	patternProjectAndCapture.projectAndCapture();
	phaseWrapper.compute();
	phaseUnwrapper.compute();
	correspondeceEstimator.compute();
	triangulator.compute();
	pointCloudExporter.save();

	return;
}
