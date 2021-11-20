#include<iostream>

using namespace std;

//Objectクラス
//x, y, z座標を保存する変数、Update関数を持つ。
//Update関数はvirtualで作ってください。

class Object
{
public:
	virtual void SetVec(float x, float y, float z)
	{
		vec_x = x;
		vec_y = y;
		vec_z = z;
	}
	virtual void SetVecX(float index)
	{
		vec_x = index;
	}
	virtual void SetVecY(float index)
	{
		vec_y = index;
	}
	virtual void SetVecZ(float index)
	{
		vec_z = index;
	}
	float getVecX()
	{
		return vec_x;
	}
	float getVecY()
	{
		return vec_y;
	}
	float getVecZ()
	{
		return vec_z;
	}

	virtual void Update()
	{
		cout << "x=" << vec_x << ",y=" << vec_y << ",z=" << vec_z << endl;
	}
protected:
	float vec_x = 0;
	float vec_y = 0;
	float vec_z = 0;
};
//Vehicle(乗り物)クラス
//Objectクラスを継承したクラス。
//ここではsetSpeed関数を追加してください。
//またspeedとaccelの変数をここで追加してください。
//setSpeed関数はvirtualで作ってください。
//(正確な速度の処理を行いたい場合は、向きと加速度で、
//	ベクトルを計算する方法でも構いません。)
class Vehicle : public Object
{
public:
	virtual void SetSpeed(float index)
	{
		Speed = index;
	}
	virtual void SetAccel(float index)
	{
		Accel = index;
	}
	//正直、protectedにしているから、ここではgeterいらない気がします
	virtual float getSpeed()
	{
		return Speed;
	}
	virtual float getAccel()
	{
		return Accel;
	}
	//Objectクラスで持ってるUpdateを上書きで、こっちを適応する
	virtual void Update()
	{
		//protectedなのでそのままvecを参照できる	
		cout << "x=" << vec_x << ",y=" << vec_y << ",z=" << vec_z << endl;
		cout << "Speed=" << Speed << endl;
	}
protected:
	float Speed = 0;
	float Accel = 0;
};
//	Car(車)クラス
//	Vehicleクラスを継承したクラス
//	Speedの変更をここでCar用に実装してください。
//
//	流れを理解するという意味で、
//	この親クラスから派生クラスを作っていってほしいので、
//	中の計算処理やデータの設定の仕方は、
//	適当に行ってもらって結構です。
class Car : public Vehicle
{
public:
	Car();

	//関数名一緒であれば大丈夫、引数はなくても2つの関数として認識されない
	//SetSppedは新しく定義
	//SetAccelはVehicleクラスのを使う
	virtual void SetSpeed()
	{
		Speed = Accel + Speed;
	}

};
Car::Car()
{
	Speed = 0;
	Accel = 0;
};

//	また、このクラスは必ず提出してください。
//	成績に加味します。
//
//	時間があれば、
//	Vehicleクラスを継承して、
//	bicycle(自転車)やbike(オートバイ)
//	といったクラスの作成や、
//	Carをさらに継承したpolice carや、truckなどの
//	クラスを作成してみてください。
class Bike : public Vehicle
{
public:
	Bike();
	//SetSppedは新しく定義
	//SetAccelはVehicleクラスのを使う
	virtual void SetSpeed()
	{
		Speed = Speed + (Accel * gear);
	}
	void SetGear(int index)
	{
		if (index <= 0 || index > 6)
		{
			cout << "gearの値は1～6の間で設定してください" << endl;
			return;
		}
		gear = index;
	}

	int GetGear()
	{
		return gear;
	}
	//Bikeをほかで継承することないと仮定し、privateにしてます
private:
	int gear = 1;
};

Bike::Bike()
{
	//値初期化
	Speed = 0;
	Accel = 0;
}

int main()
{
	int select = 3;
	bool flag = false;
	cout << "実行したい方を選択してください" << endl;
	cout << "Carは0、Bikeは1　と入力してください" << endl;
	while (!flag)
	{
		cin >> select;
		if (select == 0 || select == 1)
		{
			flag = true;
		}
		else
		{
			cout << "Carは0、Bikeは1　と入力してください" << endl;
			continue;
		}
	}
	if (select == 0)
	{
		cout << "Car実行中" << endl;
		//実体生成
		Car car;
		//アクセルの値を設定
		car.SetAccel(2);
		for (int i = 0; i < 50; i++)
		{
			//Speedの加算
			car.SetSpeed();
			//更新
			car.Update();
		}
	}
	else if (select == 1)
	{
		cout << "Bike実行中" << endl;
		//実体生成
		Bike bike;
		//ギアの値を入れる
		bike.SetGear(3);
		//値を監視したいので、一回出します
		cout << "ギア=" << bike.GetGear() << endl;
		//アクセル値を入れる
		bike.SetAccel(2);
		for (int i = 0; i < 30; i++)
		{
			//Speedの加算
			bike.SetSpeed();
			//更新
			bike.Update();
		}
	}
}
