#define Pi (22.0 / 7.0)



class PatternGenerator
{

	public:
		generatePatterns();


	private:
		unsigned int nFringePatterns;
		unsigned int nGrayCodedPatternsVertical;
		unsigned int nGrayCodedPatternsHorizontal;
		unsigned int nGrayCodesVertical;
		unsigned int nGrayCodesHorizontal;
		unsigned int fringeWidthVertical;
		unsigned int fringeWidthHorizontal;	
		
		initialize();
};
