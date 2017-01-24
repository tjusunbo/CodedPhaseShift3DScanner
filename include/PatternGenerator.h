class PatternGenerator
{

	public:
		generate();

	private:
		// data members
		size_t nGrayCodesVertical;
		size_t nGrayCodedPatternVertical;
		size_t nGrayCodesHorizontal;
		size_t nGrayCodedPatternsHorizontal;
		vector<IplImage*> generatedFringePatternsVertical;
		vector<IplImage*> generatedFringePatternsHorizontal;
		vector<IplImage*> generatedGrayCodedPatternsVertical;		       vector<IplImage*> generatedGrayCodedPatternsHorizontal;
		vector<IplImage*> generatedInverseGrayCodedPatternsVertical;
		vector<IplImage*> generatedInverseGrayCodedPatternsHorizontal;
		// member functions
		void initialize();
};
