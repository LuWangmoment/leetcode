class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		int max = getMax(A, n);
		//�������
		int * pInt = new int[max+1];
		//��������ʼ��Ϊȫ0
		for (int i = 0; i < max + 1; i++){
			*(pInt + i) = 0;
		}
        //��A����ÿһ�����ֶ�Ӧ�ı��λ��Ϊ1��������齫��ʣ��һ��0����Ҫ�ҵ����֣�����û��0����ôҪ�ҵ���max+1��
		for (int i = 0; i < n; i++){
			if (A[i]>0){
				*(pInt + A[i]) = 1;
			}
		}
        //�ҵ����0
		for (int i = 1; i < max + 1; i++){
			if (*(pInt + i) != 1){
				delete[] pInt;
				return i;
			}
		}
		delete[] pInt;
		return max + 1;
	}
private:
	int getMax(int A[], int n){
		int max = 0;
		for (int i = 0; i < n; i++){
			if (A[i]>max){
				max = A[i];
			}
		}
		return max;
	}
};