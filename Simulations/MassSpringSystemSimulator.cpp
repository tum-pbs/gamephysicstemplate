#include "MassSpringSystemSimulator.h"

int massPointCount = 0;
int springCount;
float m_fSphereSize = 0.05f;
struct massPoints {
	Vec3 mPPos;
	Vec3 mPVel;
	bool mpFix;
} massPointsArray[5];

MassSpringSystemSimulator::MassSpringSystemSimulator() {

	m_iTestCase = 0;
	m_fMass = 1;
	m_fStiffness = 1;
	m_fDamping = 1;
	m_iIntegrator = 1;

	
}

//TODO
const char* MassSpringSystemSimulator::getTestCasesStr() {
	return "Demo 1,Demo 2,Demo 3,Demo 4";
}

//TODO add to UI, 
void MassSpringSystemSimulator::reset() {
	m_mouse.x = m_mouse.y = 0;
	m_trackmouse.x = m_trackmouse.y = 0;
	m_oldtrackmouse.x = m_oldtrackmouse.y = 0;
}

//TODO
void MassSpringSystemSimulator::initUI(DrawingUtilitiesClass* DUC) //UI Elements
{
	this->DUC = DUC;
	switch (m_iTestCase)
	{
	case 0:break;//demo1
	case 1:break;//demo2
	case 2:break;//demo3
	case 3:break;//demo4
	default:break;
	}
}

//TODO
void MassSpringSystemSimulator::notifyCaseChanged(int testCase) //notifies CLI
{
	m_iTestCase = testCase;
	switch (m_iTestCase)
	{
	case 0:
		cout << "Demo 1!\n";
		cout <<"Test Case " << m_iTestCase << "\n";

		break;
	case 1:
		cout << "Demo 2!\n";
		cout << "Test Case " << m_iTestCase << "\n";
		break;
	case 2:
		cout << "Demo 3!\n";
		cout << "Test Case " << m_iTestCase << "\n";
		break;
	case 3:
		cout << "Demo 4!\n";
		cout << "Test Case " << m_iTestCase << "\n";
		break;

	default:
		cout << "Empty Test!\n";
		break;
	}
}


//TODO
void MassSpringSystemSimulator::externalForcesCalculations(float timeElapsed)
{

}


//TODO
void MassSpringSystemSimulator::simulateTimestep(float timeStep)
{
	switch (m_iTestCase)
	{
	case 0:break;
	case 1:break;
	case 2:break;
	case 3:break;
	default:break;
	}

}


void MassSpringSystemSimulator::setMass(float mass) {
	m_fMass = mass; 
}


void MassSpringSystemSimulator::setStiffness(float stiffness) {
	m_fStiffness = stiffness;
}

void MassSpringSystemSimulator::setDampingFactor(float damping) {
	m_fDamping = damping;
}

//TODO
int MassSpringSystemSimulator::addMassPoint(Vec3 position, Vec3 Velocity, bool isFixed) {
	//drawsphere at position
	massPointsArray[massPointCount] = { position, Velocity, isFixed };
	
	std::mt19937 eng;
	std::uniform_real_distribution<float> randCol(0.0f, 1.0f);
	std::uniform_real_distribution<float> randPos(-0.5f, 0.5f);
	
	DUC->setUpLighting(Vec3(), 0.4 * Vec3(1, 1, 1), 100, 0.6 * Vec3(randCol(eng), randCol(eng), randCol(eng)));
	DUC->drawSphere(Vec3(position), Vec3(m_fSphereSize, m_fSphereSize, m_fSphereSize));
			
	
	massPointCount++;
	if (massPointCount > 4) {
		massPointCount = 4;
	}
	

	return 1;
}

//TODO Render Demos
void MassSpringSystemSimulator::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
	switch (m_iTestCase)
	{
	case 0:
		drawDemo1();
		break;//demo1
	case 1:break;//demo2
	case 2:break;//demo3
	case 3:break;//demo4
	default:break;
	}


}
//TODO
void MassSpringSystemSimulator::addSpring(int masspoint1, int masspoint2, float initialLength) {
	//point MassPoint array index to start and end pos
	Vec3 lineStart = massPointsArray[masspoint1].mPPos;
	Vec3 lineEnd = massPointsArray[masspoint2].mPPos;
	Vec3 red = (1.0f, 0.0f, 0.0f);
	std::mt19937 eng;
	std::uniform_real_distribution<float> randCol(0.0f, 1.0f);
	DUC->beginLine();
	DUC->drawLine(lineStart, Vec3(randCol(eng), randCol(eng), randCol(eng)), lineEnd, Vec3(randCol(eng), randCol(eng), randCol(eng)));
	DUC->endLine();
	springCount++;
}

//TODO
int MassSpringSystemSimulator::getNumberOfMassPoints() {
	return massPointCount;
}

//TODO
int MassSpringSystemSimulator::getNumberOfSprings() {
	return springCount;
}

//TODO
Vec3 MassSpringSystemSimulator::getPositionOfMassPoint(int index) {
	return Vec3();
}

//TODO
Vec3 MassSpringSystemSimulator::getVelocityOfMassPoint(int index) {
	return Vec3();
}

//TODO
void MassSpringSystemSimulator::applyExternalForce(Vec3 force) {

}



void MassSpringSystemSimulator::onClick(int x, int y)
{
	m_trackmouse.x = x;
	m_trackmouse.y = y;
}


void MassSpringSystemSimulator::onMouse(int x, int y)
{
	m_oldtrackmouse.x = x;
	m_oldtrackmouse.y = y;
	m_trackmouse.x = x;
	m_trackmouse.y = y;
}

void  MassSpringSystemSimulator::drawDemo1() {
	addMassPoint(Vec3(0.0f, 0.0f, 0.0f), Vec3(-1,0,0), true);
	addMassPoint(Vec3(0.0f, 2.0f, 0.0f), Vec3(0, 1, 0), false);
	addSpring(0, 1, 1.0f);
}