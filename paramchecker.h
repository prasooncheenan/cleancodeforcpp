#include  <vector>
#include <map>
#include <string>
#include <limits>
#include <functional>

const std::string BPM = "bpm";
const std::string SPO = "spo2";
const std::string RESP = "respRate";

class HealthResult
{
	std::map<std::string,bool> vals;

public:
	void AddResult(std::string keyHealth, bool status)
	{
		vals[keyHealth] = status;
	}
	explicit operator bool()
	{
		
		for (auto mapValue:vals)
		{
			if (!mapValue.second)
				return false;
		}
		
		return true;
	};

};

class Limits
{
	std::map<std::string, std::pair<float, float>> _limitMap;

public:
	Limits()
	{
		_limitMap[BPM] = std::make_pair(70, 150);
		_limitMap[SPO] = std::make_pair(80, std::numeric_limits<float>::max());
		_limitMap[RESP] = std::make_pair(30, 60);
	}
	std::pair<float, float> GetLimits(std::string key)
	{
		return _limitMap[key];
	}

	void SetLimits(std::string key, std::pair<float, float> limits)
	{
		_limitMap[key] = limits;
		
	}
};
bool vitalsAreOk(float bpm, float spo2, float respRate);
