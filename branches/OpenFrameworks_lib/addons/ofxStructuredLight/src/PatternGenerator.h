#pragma once

#ifdef OPENFRAMEWORKS_AVAIL
#include "ofMain.h"
#else
#include <cv.h>
#endif

#include "libexport.h"

class DLL_EXPORT PatternGenerator {
protected:
	bool reverse;
	int width, height;
#ifdef OPENFRAMEWORKS_AVAIL
	std::vector<ofImage> sequence;
#else
	std::vector<IplImage> sequence;
#endif
	void allocateSequence(int n);
public:
	PatternGenerator();
	void setSize(int width, int height);
	void setReverse(bool reverse);
	virtual void generate() = 0;
	int getWidth();
	int getHeight();
	int size();
	void applyLut(string filename);
#ifdef OPENFRAMEWORKS_AVAIL
	ofImage& get(int i);
#else
	IplImage& get(int i);
#endif
};
