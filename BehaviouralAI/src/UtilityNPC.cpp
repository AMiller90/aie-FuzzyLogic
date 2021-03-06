#include "UtilityNPC.h"

UtilityNPC::~UtilityNPC()
{

}

void UtilityNPC::selectAction(float a_fdeltaTime)
{
	m_waterValue.setValue(getWaterValue());
	m_foodValue.setValue(getFoodValue());
	m_restValue.setValue(getRestValue());
	m_logValue.setValue(getNumberOfLogs());

	float fBestScore = 0.0f;
	Resource strBestAction = Resource::BuildHouse;
	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}
	}

	if (strBestAction == Resource::Food)
	{
		collectFood(a_fdeltaTime);
	}
	else if (strBestAction == Resource::Water)
	{
		collectWater(a_fdeltaTime);
	}
	else if (strBestAction == Resource::Rest)
	{
		rest(a_fdeltaTime);
	}
	else if (strBestAction == Resource::Logs)
	{
		chopTree(a_fdeltaTime);
	}
	else if (strBestAction == Resource::BuildHouse)
	{
		buildHouse(a_fdeltaTime);
	}
}