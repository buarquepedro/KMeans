#include "FeaturedVector.h"

FeaturedVector::FeaturedVector() {
	this->clusterIndex = -1;
	this->vectorIndex = -1;
	this->targetClass = -1;
}

FeaturedVector::FeaturedVector(std::vector<double> &features) {
	this->features = features;
	this->clusterIndex = -1;
	this->vectorIndex = -1;
	this->targetClass = -1;
}

void FeaturedVector::setFeatures(std::vector<double> &features) {
	this->features = features;
}

void FeaturedVector::setClusterIndex(signed int index) {
	this->clusterIndex = index;
}

void FeaturedVector::setVectorIndex(signed int index) {
	this->vectorIndex = index;
}

void FeaturedVector::setTargetClass(double targetClass) {
	this->targetClass = targetClass;
}

void FeaturedVector::appendFeature(double feature) {
	this->features.push_back(feature);
}

double FeaturedVector::getTargetClass() const{
	return this->targetClass;
}

double FeaturedVector::popFeature() {
	double backFeature = this->features.back();
	this->features.pop_back();
	return backFeature;
}

signed int FeaturedVector::getClusterIndex() const{
	return this->clusterIndex;
}

signed int FeaturedVector::getVectorIndex() const{
	return this->vectorIndex;
}

std::string FeaturedVector::toString() const {
	std::string vectorToString = "";

	for (unsigned i = 0; i < this->features.size(); ++i) {

		if (i != this->features.size() - 1) {
			vectorToString += std::to_string((int)this->features[i]) + " "; 
		} else {
			vectorToString += std::to_string((int)this->features[i]);
		}
	}

	return "[" + vectorToString + "]" + " [" + std::to_string((int) this->getTargetClass()) + "]";
}

std::vector<double> FeaturedVector::getFeatures() const{
	return this->features;
}

FeaturedVector& FeaturedVector::operator=(const FeaturedVector &featuredVector) {
	if (this == &featuredVector)
		return *this;

	this->clusterIndex = featuredVector.getClusterIndex();
	this->vectorIndex = featuredVector.getVectorIndex();
	this->features.clear();
	this->features = featuredVector.getFeatures();

	return *this;
}