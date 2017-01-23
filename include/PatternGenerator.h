class PatternGenerator
{

	public:
		generate();

	private:
		void initialize();
		vector<IplImage*> generatedFringePatternsVertical;
		vector<IplImage*> generatedFringePatternsHorizontal;
		vector<IplImage*> generatedGrayCodedPatternsVertical;	
		vector<IplImage*> generatedGrayCodedPatternsHorizontal;
		vector<IplImage*> generatedInverseGrayCodedPatternsVertical;
		vector<IplImage*> generatedInverseGrayCodedPatternsHorizontal;
};
