#ifndef VECTOR_H
#define VECTOR_H
class Vector {
public:
	const static unsigned long n = 3;
Vector(){
	for (int i = 0; i < n; i++)
		coords_[i]=0;
};
explicit Vector(double num){
	for (int i = 0; i < n; i++)
		coords_[i]=num;
};
Vector(const Vector &other){
	for (int i = 0; i < n; i++)
		coords_[i]=other.coords_[i];
};
Vector &operator=(const Vector &other){
	for (int i = 0; i < n; i++)
		coords_[i]=other.coords_[i];
	return *this;
};
double operator[](int i) const{
	return coords_[i];
};
double &operator[](int i){
	return coords_[i];
};
Vector &operator+=(const Vector &other){
	for (int i = 0; i < n; i++)
		coords_[i]=coords_[i]+other.coords_[i];
	return *this;
};
Vector &operator-=(const Vector &other){
	for (int i = 0; i < n; i++)
		coords_[i]=coords_[i]-other.coords_[i];
	return *this;
};
Vector &operator*=(double num){
	for (int i = 0; i < n; i++)
		coords_[i]=coords_[i]*num;
	return *this;
};
Vector &operator/=(double num){
	for (int i = 0; i < n; i++)
		coords_[i]=coords_[i]/num;
	return *this;
};
friend bool operator==(const Vector &lhs, const Vector &rhs){
	for (int i = 0; i < n; ++i)
		if (lhs.coords_[i] != rhs.coords_[i])
			return false;
	return true;
};
friend Vector operator+(const Vector &our, const Vector &other){
	Vector Vector_(our);
	for (int i = 0; i < n; i++)
		Vector_.coords_[i]=Vector_.coords_[i]+other.coords_[i];
	return Vector_;
};
friend Vector operator-(const Vector &our, const Vector &other){
	Vector Vector_(our);
	for (int i = 0; i < n; i++)
		Vector_.coords_[i]=Vector_.coords_[i]-other.coords_[i];
	return Vector_;
};
friend Vector operator*(const Vector &our, double num){
	Vector Vector_(our);
	for (int i = 0; i < n; i++)
		Vector_.coords_[i]=Vector_.coords_[i]*num;
	return Vector_;
};
friend Vector operator*(double num, const Vector &our){
	Vector Vector_(our);
	for (int i = 0; i < n; i++)
		Vector_.coords_[i]=Vector_.coords_[i]*num;
	return Vector_;
};
friend Vector operator/(const Vector &our, double num){
	Vector Vector_(our);
	for (int i = 0; i < n; i++)
		Vector_.coords_[i]=Vector_.coords_[i]/num;
	return Vector_;
};
friend double operator^(const Vector &our, const Vector &other){
	double sum_return = 0;
	for (int i = 0; i < n; i++)
		sum_return=sum_return+our.coords_[i]*other.coords_[i];
	return sum_return;
};
Vector operator-()const{
	return (Vector(*this)=Vector(*this)*(-1));
};
private:
	double coords_[n];
};
bool operator!=(const Vector &our, const Vector &other){
	return !(our == other);
};
#endif // VECTOR_H
