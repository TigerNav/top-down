#include "FindMapLayer.h"

sf::FloatRect FindMapLayer::FindObjectLayer(std::string Layer) {
	const auto& layers = map.Loader.getLayers();

	for (const auto& layer : layers) {
		if (layer.name == Layer) {
			for (const auto& object : layer.objects)
			{
				return object.getAABB();
			}
		}
		else
			std::cout << "could not find layer" << std::endl;
	}
}
