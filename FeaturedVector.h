#ifndef FEATURED_VECTOR_H
#define FEATURED_VECTOR_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class FeaturedVector {

public:
	FeaturedVector();
	FeaturedVector(std::vector<double> &features);
	void setFeatures(std::vector<double> &features);
	void setClusterIndex(signed int index);
	void setVectorIndex(signed int index);
	void setTargetClass(double targetClass);
	void appendFeature(double feature);
	double getTargetClass() const;
	double popFeature();
	signed int getClusterIndex() const;
	signed int getVectorIndex() const;
	std::string toString() const;
	std::vector<double> getFeatures() const;
	FeaturedVector& operator=(const FeaturedVector &featuredVector);
	
private:
	std::vector<double> features;
	double targetClass;
	signed int clusterIndex;
	signed int vectorIndex;
};

#endif // FEATURED_VECTOR_H
