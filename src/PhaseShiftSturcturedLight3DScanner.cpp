// executes 3D scanning pipeline
#include "PhaseShiftSturcturedLight3DScanner.h"



void PhaseShiftStructuredLight3DScaner::scanObject(string *configFileName)
{

	allocatePipelineMemory();
	
	// read config file and initialize a global set of variables.
	initializeGlobalVariables();

	systemCalibrator.calibrate();
	patternGenerator.generate(configFileName);
	patternProjectAndCapture.projectAndCapture();
	phaseWrapper.compute();
	phaseUnwrapper.compute();
	correspondeceEstimator.compute();
	triangulator.compute();
	pointCloudExporter.save();

	return;
}
