#ifndef MERGER_H_
#define MERGER_H_

class Merger {
public:
	Merger(std::string outdir);
	Termino nextTermino();
	bool end();
private:
	std::string outdir;
};

#endif
