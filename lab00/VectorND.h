
class VectorND {

  private:
		float* c;
		int alloc;

		void resize(int newSize);
 
  public:

    VectorND(); 
    VectorND(const int size);
		~VectorND();
    float getCoordinate(const int i)const;
	  void setCoordinate(const int i, const float val);
		bool checkDim(const VectorND& other) const;		
  	VectorND(const VectorND& copy);
    float magnitude() const;
			
		int length() const; 
   // VectorND(float x, float y, float z); 
    
    void normalize();
    VectorND operator+(const VectorND& other)const; // vector sum
    float operator*(const VectorND& other)const; // dot product
		void absoluteValue();
		
		};

