
git commit  提交

git branch [name] 创建分支

git checkout [name] 切换分支
git checkout [提交记录] 分离HEAD就是让其指向一个提交记录而不是分支名
git merge [name]
		创建新分支 bugFix
		用 git checkout bugFix 切换到 bugFix分支
		提交一次
		用 git checkout 切换回 master
		再提交一次
		用 git merge 合并 bugFix分支进 master
git rebase	线性链接
		新建bugFix分支
		提交一次
		切换回 master 分支再提交一次
		再次切换到 bugFix 分支，rebase 到 master 上
		从bugFix 上git rebase master
		更新到master git rebase bugFix
在git中前后移动
		> git checkout [提交记录]
		> 使用^向上移动1个提交记录   
	 	> master^相当于"master的父提交
		> 可以一直使用HEAD^向上移动。
		> > >使用~<num>向上移动多个提交记录
		git branch -f master HEAD~3
			-f (强制)移动master指向HEAD的第3级父提交
cherry-pick

reset

revert



merge
http://pcottle.github.io/learnGitBranching
