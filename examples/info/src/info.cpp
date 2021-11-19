import std;
import synodic.soul.engine;

class Info : public synodic::soul::App
{
public:
	explicit Info(const synodic::soul::Parameters& params = synodic::soul::Parameters()) :
		App(params)
	{
	}
};

std::int32_t main(std::int32_t, char*[])
{
	const synodic::soul::Parameters appParams;
	Info app(appParams);

	app.Run();

}
