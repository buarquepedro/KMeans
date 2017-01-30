#ifndef CLUSTER_H
#define CLUSTER_H

#include "FeaturedVector.h"
#include <cassert>
#include <cmath>

class Cluster {

public:
	Cluster();
	Cluster(FeaturedVector &centroid);
	void displayCluster();
	void recalculateCentroid();
	void appendToCluster(FeaturedVector &feature);
	void setClusterIndex(signed int index);
	void setCentroid(FeaturedVector &centroid);
	bool removeFromCluster(signed int featureID);
	signed int getClusterIndex();
	signed int getTotalPoints();
	signed int getCorrect();
	FeaturedVector& getCentroid();

private:
	FeaturedVector centroid;
	std::vector<FeaturedVector> cluster;
	signed int clusterIndex;
};


#endif // CLUSTER_H

