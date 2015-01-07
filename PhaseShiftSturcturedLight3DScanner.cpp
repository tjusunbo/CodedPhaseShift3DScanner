// executes 3D scanning pipeline


void readScannerConfiguration()
{
nFringePatterns = ;
nGrayCodedPatternsVertical = ;
nGrayCodedPatternsHorizontal = ;
nGrayCodesVertical = ;
nGrayCodesHorizontal = ;
fringeWidthVertical = ;
fringeWidthHorizontal = ;
triangulationMethod = ;
projectorImageWidth = ;
projectorImageHeight = ;
cameraImageWidth = ;
cameraImageHeight = ;

projectorGamma = ;
projectorBrightness = ;
cameraGamma = ;
cameraBrightness = ;
projectorFocus = ;
cameraFocus = ;

}


void systemCalibration()
{
}

void generatePatterns()
{
}


void projectAndCapturePatterns()
{
}

void computeWrappedPhase()
{
}


void computeUnwrappedPhase()
{
}

void computeProjectorCameraCorrespondence()
{
}

void triangulate()
{
}

void savePointCloud()
{
}

void scanObject()
{
	readScannerConfiguration();
	systemCalibration();
	generatePatterns();
	projectAndCapturePatterns();
	computeWrappedPhase();
	computeUnwrappedPhase();
	computeProjectorCameraCorrespondence();
	triangulate();
	savePointCloud();

	return;
}
