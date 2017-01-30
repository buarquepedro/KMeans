#include "Kmeans.h"

Kmeans::Kmeans(unsigned K) {
	this->K = K;
	this->clusters.resize(K);
}

double Kmeans::euclideanDistance(FeaturedVector p1, FeaturedVector p2) {
	assert(p1.getFeatures().size() == p2.getFeatures().size());

	double sum = 0.0;
	for (unsigned i = 0; i < p1.getFeatures().size(); ++i) {
		sum += (p1.getFeatures()[i] - p2.getFeatures()[i])*(p1.getFeatures()[i] - p2.getFeatures()[i]);
	}

	return sqrt(sum);
}

signed int Kmeans::getClosestClusterIndex(FeaturedVector &featuredVector) {
	signed int index = this->clusters[0].getClusterIndex();
	double minDist = this->euclideanDistance(this->clusters[0].getCentroid(), featuredVector);

	for (unsigned i = 1; i <  this->clusters.size(); ++i) {
		double dist = this->euclideanDistance(this->clusters[i].getCentroid(), featuredVector);

		if (dist < minDist) {
			index = this->clusters[i].getClusterIndex();
			minDist = dist;
		}
	}

	return index;
}

void Kmeans::fit(std::vector<FeaturedVector> dataSet) {
	srand(time(nullptr));
	unsigned int points = dataSet.size();
	std::vector<unsigned int> choosenIndexes;

	for (int k = 0; k < this->K; ++k) {
		int centroidIndex = rand() % points;

		while (std::find (choosenIndexes.begin(), choosenIndexes.end(), centroidIndex) != choosenIndexes.end()) {
			centroidIndex = rand() % points;
		}

		choosenIndexes.push_back(centroidIndex);
	}

	this->clusters.resize(this->K);
	for (unsigned k = 0; k < this->K; ++k) {
		this->clusters[k].setCentroid(dataSet[choosenIndexes[k]]);
		this->clusters[k].setClusterIndex(k);
	}

	bool isDone = false;
	while (!isDone) {
		
		isDone = true;
		for (unsigned i = 0; i < dataSet.size(); ++i) {
			signed int appropriateIndex = this->getClosestClusterIndex(dataSet[i]);

			if (dataSet[i].getClusterIndex() == -1) {
				this->clusters[appropriateIndex].appendToCluster(dataSet[i]);
				dataSet[i].setClusterIndex(appropriateIndex);
			} else if(dataSet[i].getClusterIndex() != appropriateIndex) {
				this->clusters[dataSet[i].getClusterIndex()].removeFromCluster(dataSet[i].getVectorIndex());
				this->clusters[appropriateIndex].appendToCluster(dataSet[i]);
				dataSet[i].setClusterIndex(appropriateIndex);
				isDone = false;
			}
		}

		for (Cluster c : this->clusters) {
			c.recalculateCentroid();
		}
	}
}

signed int Kmeans::predict(FeaturedVector &testPoint) {
	return this->getClosestClusterIndex(testPoint);
}

void Kmeans::displayClusters() {
	for (Cluster c : this->clusters) {
		c.displayCluster();
	}
	std::cout << std::endl;
}