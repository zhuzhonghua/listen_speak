#include "zengine.h"
#include "listenspeak.h"
#include "mainscene.h"

int main(int argc, char** argv)
{
	ListenSpeak ls;
	ls.init();

	ls.switchScene(new MainScene());
	ls.run();
	
	ls.finish();
  return 0;
}
