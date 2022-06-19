#include "Neighbor.h"

/**
 * @brief Construct a new Neighbor:: Neighbor object
 *
 * @param key neighbor id
 * @param weight edge weight between the vertex and the neighbor
 */
Neighbor::Neighbor(int key, int weight)
{
  this->key = key;
  this->weight = weight;
}
