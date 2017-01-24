add_executable (3dScanner PatternGenerator.cpp PatternProjectAndCapture.cpp PhaseWrapper.cpp PhaseUnwrapper.cpp SystemCalibrator.cpp Triangulator.cpp PhaseShiftStructuredLight3DScanner.cpp main.cpp)

target_link_libraries (3dScanner opencv_highgui)


