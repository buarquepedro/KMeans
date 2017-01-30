#ifndef KMEANS_H
#define KMEANS_H

#include "Cluster.h"
#include <algorithm>
#include <ctime>

class Kmeans {
public:
	Kmeans(unsigned K = 2);
	void fit(std::vector<FeaturedVector> dataSet);
	double euclideanDistance(FeaturedVector p1, FeaturedVector p2);
	signed int predict(FeaturedVector &testPoint);
	signed int getClosestClusterIndex(FeaturedVector &featuredVector);
	void displayClusters();

private:
	std::vector<Cluster> clusters;
	const double tolerance = 10;
	unsigned K;
};

#endif // KMEANS_H

