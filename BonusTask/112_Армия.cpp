#include <iostream>
#include <vector>

struct Set {
    const int part_size = 100;
    
    std::vector<int> a;
    std::vector<int> s;
    
    Set(const int n)
        :a(n, 0)
        , s((n + part_size - 1) / part_size, 0)
        {}
    void add(const int index) {
        a[index]++;
        s[index / part_size]++;
    }
    int countUp(const int index) const{
        int partEnd = (index + part_size - 1) / part_size * part_size;
        int sum = 0;
        for(int i = index; i < (int)a.size() && i < partEnd; i++){
            sum += a[i];
        }
        for(int i = partEnd / part_size; i < (int)s.size(); i++){
            sum += s[i];
        }
        return sum;
    }
};

int main() {

    int n, nRows;
    scanf("%d %d", &n, &nRows);
    int answer = 0;
    for(int row = 0; row < nRows; row++){
        Set set(n);
        for(int i = 0; i < n; i++){
            int value;
            scanf("%d", &value);
            value--;
            answer += set.countUp(value + 1);
            set.add(value);
        }
    }
    printf("%d", answer);
    return 0;
}

/*
Идея:
n - рост солдат
nRows - число ряд
Мы здесь идем по ряду слева направо, для каждого солдата находим, сколько было солдат такого роста или выше. Добавляем в сумму, потом заносим 1 в структуру для этого солдата.  
*/
