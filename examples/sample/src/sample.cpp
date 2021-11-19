import std;
import synodic.soul.engine;

class Sample : public synodic::soul::App
{
public:
	explicit Sample(const synodic::soul::Parameters& params = synodic::soul::Parameters()) :
		App(params)
	{
	}
};

std::int32_t main(std::int32_t, char*[])
{
	const synodic::soul::Parameters appParams;
	Sample app(appParams);

	app.Run();

}
