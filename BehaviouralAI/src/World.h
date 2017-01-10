#ifndef WORLD_H_
#define WORLD_H_

#include "glm/glm.hpp"

class World
{
public:
	World();
	~World();

	void render();

	void addLogToHouse();
	void addLogToHouse2();
	unsigned int getHouseLogsRequired() const { return m_uiHouseLogsRequired;  }
	unsigned int getCurrentHouseLogs() const { return m_uiHouseCurrentLogs; }
	unsigned int getCurrentHouse2Logs() const { return m_uiHouse2CurrentLogs; }
	bool isHouseBuilt() { return m_uiHouseCurrentLogs == m_uiHouseLogsRequired;  }
	bool isHouse2Built() { return m_uiHouse2CurrentLogs == m_uiHouseLogsRequired; }
	bool checkAllHousesBuilt() { return isHouseBuilt() && isHouse2Built(); }

	glm::vec3 getHouseLocation() const;
	glm::vec3 getHouseLocation2() const;
	glm::vec3 getTreeLocation() const;
	glm::vec3 getWaterLocation() const;
	glm::vec3 getFoodLocation() const;
	glm::vec3 getRestedLocation() const;

	bool interactWithFood();
	bool interactWithWater();
	bool interactWithRested();

	bool interactWithTree();
	bool interactWithHouse();
private:
	unsigned int m_uiHouseLogsRequired;
	unsigned int m_uiHouseCurrentLogs;
	unsigned int m_uiHouse2CurrentLogs;

	glm::vec3 m_houseLocation;
	glm::vec3 m_houseLocation2;
	glm::vec3 m_treeLocation;


	glm::vec3 m_waterLocation;
	glm::vec3 m_foodLocation;
	glm::vec3 m_restedLocation;

	bool m_bAllHousesBuilt;
	float m_fHouseInteractTime;
	float m_fTreeInteractTime;
	float m_fFoodInteractTime;
	float m_fWaterInteractTime;
	float m_fRestedInteractTime;

	float m_fLastHouseInteractTime;
	float m_fLastTreeInteractTime;
	float m_fLastWaterInteractTime;
	float m_fLastFoodInteractTime;
	float m_fLastRestedInteractTime;
};

#endif // !WORLD_H_
