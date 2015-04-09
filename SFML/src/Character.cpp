#include "Character.h"

Character::Character()
{
	m_iHealth = 0;
	m_fMovementSpeed = 0.0f;
	m_DestinationPosition = Vector2<float>();
}

Character::~Character()
{

}

void Character::GoToPosition(Vector2<float> newDest)
{
	Vector2<float> destDiff = getPosition() - newDest;
    if (destDiff.x() == 0.0f || destDiff.y() == 0.0f) {
        fAngle = 0;
	} else {
        fAngle = atan2(destDiff.y(), destDiff.x());
    }
	printf("Angle: %f \n", fAngle);
    fAngle *= (180/ M_PI);
	float sv = sinf(fAngle) * m_fMovementSpeed;
	float sh = cosf(fAngle) * m_fMovementSpeed;
	fAngle *= 2;
	fAngle += 90;
	printf("Angle: %f \n", fAngle);
	SetVelocity(sv, -sh);
	m_DestinationPosition = newDest;
}

void Character::UpdateCharacterLogic() 
{

	UpdateGraphics();
}
