#include<iostream>

using namespace std;

//Object�N���X
//x, y, z���W��ۑ�����ϐ��AUpdate�֐������B
//Update�֐���virtual�ō���Ă��������B

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
//Vehicle(��蕨)�N���X
//Object�N���X���p�������N���X�B
//�����ł�setSpeed�֐���ǉ����Ă��������B
//�܂�speed��accel�̕ϐ��������Œǉ����Ă��������B
//setSpeed�֐���virtual�ō���Ă��������B
//(���m�ȑ��x�̏������s�������ꍇ�́A�����Ɖ����x�ŁA
//	�x�N�g�����v�Z������@�ł��\���܂���B)
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
	//�����Aprotected�ɂ��Ă��邩��A�����ł�geter����Ȃ��C�����܂�
	virtual float getSpeed()
	{
		return Speed;
	}
	virtual float getAccel()
	{
		return Accel;
	}
	//Object�N���X�Ŏ����Ă�Update���㏑���ŁA��������K������
	virtual void Update()
	{
		//protected�Ȃ̂ł��̂܂�vec���Q�Ƃł���	
		cout << "x=" << vec_x << ",y=" << vec_y << ",z=" << vec_z << endl;
		cout << "Speed=" << Speed << endl;
	}
protected:
	float Speed = 0;
	float Accel = 0;
};
//	Car(��)�N���X
//	Vehicle�N���X���p�������N���X
//	Speed�̕ύX��������Car�p�Ɏ������Ă��������B
//
//	����𗝉�����Ƃ����Ӗ��ŁA
//	���̐e�N���X����h���N���X������Ă����Ăق����̂ŁA
//	���̌v�Z������f�[�^�̐ݒ�̎d���́A
//	�K���ɍs���Ă�����Č��\�ł��B
class Car : public Vehicle
{
public:
	Car();

	//�֐����ꏏ�ł���Α��v�A�����͂Ȃ��Ă�2�̊֐��Ƃ��ĔF������Ȃ�
	//SetSpped�͐V������`
	//SetAccel��Vehicle�N���X�̂��g��
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

//	�܂��A���̃N���X�͕K����o���Ă��������B
//	���тɉ������܂��B
//
//	���Ԃ�����΁A
//	Vehicle�N���X���p�����āA
//	bicycle(���]��)��bike(�I�[�g�o�C)
//	�Ƃ������N���X�̍쐬��A
//	Car������Ɍp������police car��Atruck�Ȃǂ�
//	�N���X���쐬���Ă݂Ă��������B
class Bike : public Vehicle
{
public:
	Bike();
	//SetSpped�͐V������`
	//SetAccel��Vehicle�N���X�̂��g��
	virtual void SetSpeed()
	{
		Speed = Speed + (Accel * gear);
	}
	void SetGear(int index)
	{
		if (index <= 0 || index > 6)
		{
			cout << "gear�̒l��1�`6�̊ԂŐݒ肵�Ă�������" << endl;
			return;
		}
		gear = index;
	}

	int GetGear()
	{
		return gear;
	}
	//Bike���ق��Ōp�����邱�ƂȂ��Ɖ��肵�Aprivate�ɂ��Ă܂�
private:
	int gear = 1;
};

Bike::Bike()
{
	//�l������
	Speed = 0;
	Accel = 0;
}

int main()
{
	int select = 3;
	bool flag = false;
	cout << "���s����������I�����Ă�������" << endl;
	cout << "Car��0�ABike��1�@�Ɠ��͂��Ă�������" << endl;
	while (!flag)
	{
		cin >> select;
		if (select == 0 || select == 1)
		{
			flag = true;
		}
		else
		{
			cout << "Car��0�ABike��1�@�Ɠ��͂��Ă�������" << endl;
			continue;
		}
	}
	if (select == 0)
	{
		cout << "Car���s��" << endl;
		//���̐���
		Car car;
		//�A�N�Z���̒l��ݒ�
		car.SetAccel(2);
		for (int i = 0; i < 50; i++)
		{
			//Speed�̉��Z
			car.SetSpeed();
			//�X�V
			car.Update();
		}
	}
	else if (select == 1)
	{
		cout << "Bike���s��" << endl;
		//���̐���
		Bike bike;
		//�M�A�̒l������
		bike.SetGear(3);
		//�l���Ď��������̂ŁA���o���܂�
		cout << "�M�A=" << bike.GetGear() << endl;
		//�A�N�Z���l������
		bike.SetAccel(2);
		for (int i = 0; i < 30; i++)
		{
			//Speed�̉��Z
			bike.SetSpeed();
			//�X�V
			bike.Update();
		}
	}
}
