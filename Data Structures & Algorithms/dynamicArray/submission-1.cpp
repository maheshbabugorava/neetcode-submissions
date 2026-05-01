class DynamicArray {

    int _m_iCapacity{-1};
    int _m_iEndIndex{-1};

    int _m_iSize{0};

    int* arrayI = nullptr;


public:

    DynamicArray(int capacity) {

        if(capacity > 0){
        _m_iCapacity = capacity;

        arrayI = (int*)malloc(_m_iCapacity * sizeof(int));
        }
    }

    int get(int i) {
        if(i < _m_iSize){
            return arrayI[i];
        }

        return -1;
    }

    void set(int i, int n) {
        if(i < _m_iSize){
            arrayI[i] = n;
        }
    }

    void pushback(int n) {
        if(_m_iSize == _m_iCapacity){
            resize();
        }

        arrayI[_m_iSize] = n;
        _m_iSize += 1;
    }

    int popback() {

        int x = arrayI[_m_iSize-1];
        _m_iSize -= 1;


        return x;
    }

    void resize() {
        arrayI = (int*)realloc(arrayI, 2 * _m_iCapacity * sizeof(int));
        _m_iCapacity = 2 * _m_iCapacity;
    }

    int getSize() {
        return _m_iSize;
    }

    int getCapacity() {
        return _m_iCapacity;
    }
};
