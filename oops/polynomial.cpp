class Polynomial {
public:
  int *degCoeff; // Name of your array (Don't change this)
  int capacity;
  Polynomial() {
    degCoeff = new int[5];
    for(int i=0;i<5;i++){
      degCoeff[i]=0;
    }
    capacity = 5;
  }
  Polynomial(Polynomial const &p) {
    this->degCoeff=new int[p.capacity];
    capacity = p.capacity;
    for(int i=0;i<capacity;i++){
      this->degCoeff[i]=p.degCoeff[i];
    }
    
  }
  void operator=(Polynomial const &p) {
     this->degCoeff=new int [p.capacity];
    capacity = p.capacity;
    for(int i=0;i<capacity;i++){
      this->degCoeff[i]=p.degCoeff[i];
    }
  }
  void setCoefficient(int index, int coeff) {
    if (index < capacity) {
      degCoeff[index] = coeff;
    } else {
      int *garb = new int[index+1];
      for(int i=0;i<=index;i++){
        garb[i]=0;
      }
      for (int i = 0; i < capacity; i++) {
        garb[i] = degCoeff[i];
      }
      capacity = index + 1;
      delete[] degCoeff;
      degCoeff = garb;
      degCoeff[index] = coeff;
    }
  }
  void print() {
    for (int i = 0; i < capacity; i++) {
      if (degCoeff[i] != 0) {
        cout << degCoeff[i] << 'x' << i << " ";
      }
    }
    
  }
  Polynomial operator+(Polynomial const &p) {
    if (capacity > p.capacity) {
      for (int i = 0; i < p.capacity; i++) {
        degCoeff[i] += p.degCoeff[i];
      }
      return *this;
    } else {
      for (int i = 0; i < capacity; i++) {
        p.degCoeff[i] += degCoeff[i];
      }
      return p;
    }
  }
  Polynomial operator-(Polynomial const &p) {
    if (capacity > p.capacity) {
      for (int i = 0; i < p.capacity; i++) {
        degCoeff[i] -= p.degCoeff[i];
      }
      return *this;
    } else {
      for (int i = 0; i < capacity; i++) {
        p.degCoeff[i] -= degCoeff[i];
      }
      return p;
    }
  }
  Polynomial operator*(Polynomial const &p) {
    int index=capacity + p.capacity;
    int *result = new int[index];
    for(int i=0;i<index;i++) {
      result[i]=0;
    }
    for (int i = 0; i < capacity; i++) {
      for (int j = 0; j < p.capacity; j++) {
        result[i + j] += degCoeff[i] * p.degCoeff[j];
      }
    }
    delete[] degCoeff;
    degCoeff = result;
    capacity += p.capacity;
    return *this;
  }
};
