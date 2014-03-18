//some generic pseudocode that shows the struct of backtracking

bool Solve(configureation conf)
{
	if(no more choices) {	//BASE CASE
		return (conf is goal state);
	}

	for (all available choices){
		try one choices c;

		ok=Solve(conf with choice c made);
		if(ok)
			return true;
		else
			unmake choice c;
	}

	return false;
}