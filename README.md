git init
git add . 
git commit -m "first commit"
git remote add origin https:
git push -u origin master


git pull origin main
1
这个命令从名为 origin 的远程的 main 分支获取更新并将它们合并到你当前的分支。如果存在任何冲突，你需要手动解决它们。
解决冲突:
如果拉取操作导致冲突，Git 会告诉你哪些文件有冲突。你必须打开这些文件并进行必要的更改来解决冲突。编辑文件后，需要将它们重新添加到索引中：

git add <文件名>
1
对所有有冲突的文件重复此操作。
提交合并:
如果拉取触发了一次合并并且需要解决冲突，你需要提交合并。如果自动合并成功而没有冲突，Git 会自动进行提交。如果你解决了冲突，那么在添加了解决后的文件后，进行提交：

git commit -m "Merge branch 'main' of https://github.com/....git"
1
推送你的更改:
一旦你的本地分支是最新的并且任何冲突都已解决，你就可以再次尝试推送：

git push -u origin main
1
-u 标志为你的本地分支设置了上游引用，意味着将来你可以简单地调用 git push 或 git pull 而不需要指定分支。
