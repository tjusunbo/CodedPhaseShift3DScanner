class PatternProjectAndCapture
{
	public:
		projectAndCapture();
	private:
		initialize();
		vector<IplImage*> projectedFringePatternsVertical;
		vector<IplImage*> projectedFringePatternsHorizontal;
		vector<IplImage*> projectedGrayCodesVertical;
		vector<IplImage*> projectedGrayCodesHorizontal;
		vector<IplImage*> projectedInverseGrayCodesVertical;
		vector<IplImage*> projectedInverseGrayCodesHorizontal;
		unsigned int nFringePatterns;
		unsigned int fringeWidthVertical;
		unsigned int fringeWidthHorizontal
		unsigned int nGrayCodedPatternsVertical;
		unsigned int nGrayCodedPatternsHorizontal;
		
};
