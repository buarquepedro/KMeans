#include "Cluster.h"

Cluster::Cluster() {
	this->clusterIndex = -1;
}

Cluster::Cluster(FeaturedVector &centroid) {
	this->centroid = centroid;
	this->clusterIndex = -1;
}

void Cluster::setClusterIndex(signed int index) {
	this->clusterIndex = index;
}

signed int Cluster::getClusterIndex() {
	return this->clusterIndex;
}

void Cluster::setCentroid(FeaturedVector &centroid) {
	this->centroid = centroid;
}

FeaturedVector& Cluster::getCentroid() {
	return this->centroid;
}

void Cluster::recalculateCentroid() {
	std::vector<double> newCentroid(this->centroid.getFeatures().size(), 0.0);

	for (FeaturedVector &feature : this->cluster) {
		for (unsigned i = 0; i < feature.getFeatures().size(); ++i) {
			newCentroid[i] += feature.getFeatures()[i];
		}
	}

	for (unsigned i = 0; i < newCentroid.size(); ++i) {
			newCentroid[i] /= this->cluster.size();
	}

	FeaturedVector centroid(newCentroid);
	this->setCentroid(centroid);
}

void Cluster::appendToCluster(FeaturedVector &feature) {
	this->cluster.push_back(feature);
}

bool Cluster::removeFromCluster(signed int featureID) {
	for (unsigned i = 0; i < this->cluster.size(); ++i) {
		if (this->cluster[i].getVectorIndex() == featureID) {
			this->cluster.erase(this->cluster.begin() + i);
			return true;
		}
	}

	return false;
}

signed int Cluster::getTotalPoints() {
	return this->cluster.size();
}

signed int Cluster::getCorrect() {
	int correct = 0;

	for (FeaturedVector &f : this->cluster) {
		if (f.getTargetClass() == this->clusterIndex) {
			correct++;
		}
	}

	return correct;
}

void Cluster::displayCluster() {
	std::cout << "CLUSTER " << this->clusterIndex << ": " << std::endl;

	for (FeaturedVector &f : this->cluster) {
		std::cout << f.toString() << std::endl;
	}
}