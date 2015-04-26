class Solution {
public:
	bool ifDone = false;
	vector<int> candidates;
	vector<vector<int>> result;
	map<int, int> resultMap, candidatesMap;
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		//����
		sort(candidates.begin(), candidates.end());
		//��¼ÿ�����ֳ��ֵĸ���
		for (int i:candidates){
			if (candidatesMap.find(i) != candidatesMap.end()){
				candidatesMap[i]++;
			}
			else
			{
				candidatesMap[i] = 1;
			}
		}
		//ȥ��
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
		this->candidates = candidates;
		vector<int> temp;
		result.push_back(temp);
		//���ݷ�
		backTrack(0, target);
		if (result.back().size() == 0)
			result.pop_back();
		return result;
	}

	void backTrack(int index, int target)
	{
		if (index == candidates.size())
			return;
		int value = candidates[index];
		//����resultMap���ж��Ƿ���Լ���
		if (resultMap.find(value) != resultMap.end()){
			if (resultMap[value] == candidatesMap[value]){
				backTrack(index+1, target);
				return;
			}
			else
				resultMap[value]++;
		}
		else
		{
			resultMap[value] = 1;
		}
		result.back().push_back(value);
		if (value < target){
			backTrack(index, target - value);
		}
		else if (value > target){
			resultMap[result.back().back()]--;
			result.back().pop_back();
			return;
		}
		else {
			ifDone = true;
			return;
		}
		if (ifDone){
			vector<int> temp;
			temp = result.back();
			resultMap[temp.back()]--;
			temp.pop_back();
			result.push_back(temp);
			ifDone = false;
		}
		resultMap[result.back().back()]--;
		result.back().pop_back();
		backTrack(index + 1, target);
		return;
	}
};