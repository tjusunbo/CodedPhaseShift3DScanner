class PatternGenerator
{

	public:
		generate();

	private:
		void initialize();
		unsigned int nFringePatterns;
		unsigned int nGrayCodedPatternsVertical;
		unsigned int nGrayCodedPatternsHorizontal;
		unsigned int nGrayCodesVertical;
		unsigned int nGrayCodesHorizontal;
		unsigned int fringeWidthVertical;
		unsigned int fringeWidthHorizontal;	
		vector<IplImage*> generatedFringePatternsVertical;
		vector<IplImage*> generatedFringePatternsHorizontal;
		vector<IplImage*> generatedGrayCodedPatternsVertical;	
		vector<IplImage*> generatedGrayCodedPatternsHorizontal;
		vector<IplImage*> generatedInverseGrayCodedPatternsVertical;
		vector<IplImage*> generatedInverseGrayCodedPatternsHorizontal;
};
