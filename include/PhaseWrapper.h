#include "PhaseShiftSturcturedLight3DScanner.h"



class PhaseWrapper
{
	public:
		void compute();
	private:
		int (*valid_map_vertical)[Camera_imageheight];
		int (*valid_map_horizontal)[Camera_imageheight];

		int (*valid_map_local)[Camera_imageheight]; //indicates ROI in the image.
		float (*wrapped_phi)[Camera_imageheight];
		int (*selected_region)[Camera_imageheight];
		float (*wrapped_phi_vertical)[Camera_imageheight];
		float (*wrapped_phi_horizontal)[Camera_imageheight];
		IplImage**gray_captured_images;
		IplImage*wrapped_phase_image;
		
		// functions.
		void read_image();
	        void check_I_mod+_critera();	

	
};

