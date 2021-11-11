/*
时间限制：
	1s。
空间限制：
	256m。
题目：
	G - 深度的学习。
描述：
	他收回了思绪，现在发生的事情有点超出了他的预料。
	林浔道：“我能知道……您为什么这样做么？为什么要购买‘洛神’的股权？”

	其实他是想问三千万和二十万这件事，但男神似乎并不在意，可能在男神眼里他只值二十万，但是二十万的生意倒也不必让东君亲自来谈。
	林浔面对这巨大的落差，不得不清醒起来，面对现实：“您从哪里知道了我们？”

	他们只是个濒临破产的三人公司，请不起会计，商业计划书都是架构写的。“洛神”算法曾投给过许多公司，无一例外被拒绝。当然一年前也投给过银河，如同石沉大海。

	男神十指交扣，搭在桌面上，道：“非要说的话，我在 Github 上看到了你的部分代码。”
	说罢，他看着林浔的眼睛：“我个人很感兴趣，不知道你是否能详细向我阐释一下核心算法。”
	
	林浔的心脏在胸腔里重重跳了一下：“可以的。”
	他曾经尝试把算法解释给很多人听，但他们都认为它毫无意义，并且是多此一举。甚至连王安全和赵架构都没有真正弄懂里面的数学部分。

	这还是第一次有人主动要听他的算法。
	而且还是东君，他多年来的男神。

	面对着男神，他不可避免地有些紧张：“公式有点多，我可能需要一块白板。”
	“好的。”东君似乎并没有因为他的要求感到不悦：“讨论区在隔壁，先用用白纸代替吧。”
	说着，他在抽屉里取了纸笔，并在旁边拉开了一张座椅。

	林浔寻思着男神的意思，是让自己坐去旁边。
	他被受宠若惊的情绪控制，在东君身边坐下，拿起了碳素笔。

	离得近了，他嗅到东君身上微微冷洌的气息，像雪山深处的冰泉。

	办公桌很宽大，他拿起笔来，将白纸放在自己和东君中间，在纸面上写下一个公式，道：“主流的仿真智能系统大部分基于神经网络，或者说深度学习。但我的算法……更主要的，是在用混沌数学。”
	他微微顿了一下，果然听到东君道：“你不喜欢神经网络？”

	神经网络是现下人工智能技术的主流，有一段时间它改头换面，被称为“深度学习”，但后来又渐渐回归了本质。它将人脑的神经网络结构抽象成数学模型，然后在计算机上模拟实现，以此可以高度还原人脑对信息的处理过程，智能程度很高——机器的计算力增强后，更是如虎添翼。得到了男神三千万的 Lions 正是凭借这个领域的成果得到了青睐。

	这东西很好，但是——
	林浔抿了抿唇，道：“我觉得它不自由。”
	或者说，它不够“深”。比如，当你得到一个不断分支的关系图 A，上面挂满了且只挂着许多“学习”，可是最深的“学习”能否达到我们想要的深度 d 呢？
输入：
	输入包含多行。
	第一行为两个非负整数 n、d，n 表示关系图 A 中有 n 个关系。
	随后 n 行，每行两个字符串 x、y，以“xuexi[i]”的形式给出，i 为 1 ~ n，字符串内部无空格，字符串间使用空格分隔，表示 y 比 x 深且只深一层。
	规定 A 中最浅的学习深度为 1。
	保证 0 <= n, d <= 1e5。
输出：
	输出包含两行。
	第一行为一个非负整数，表示 A 中最深的“学习”深度。
	若最深的“学习”深度不小于 d，则在第二行中输出“deep xue xi is nb”，否则输出“shen du learning is fw”。
	输出不包含引号。
样例：
	input:
		10 4
		xuexi1 xuexi2
		xuexi1 xuexi3
		xuexi2 xuexi4
		xuexi2 xuexi5
		xuexi3 xuexi6
		xuexi3 xuexi7
		xuexi4 xuexi8
		xuexi5 xuexi9
		xuexi9 xuexi10
	output:
		5
		deep xue xi is nb
	input:
		1 14514
		xuexi1 xuexi2
	output:
		2
		shen du learning is fw
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
int f[MAXN], dep[MAXN];
int getd(int x)
{
	if (dep[x]) return dep[x];
	if (f[x] == 0) return 1;
	return dep[x] = getd(f[x]) + 1;
}
int read(string s)
{
	int res = 0;
	for (int i=5; i<s.size(); i++)
		res = res * 10 + s[i] - '0';
	return res;
}
int main()
{
	int n, d;
	cin >> n >> d;
	for (int i=1; i<n; i++)
	{
		string x, y;
		cin >> x >> y;
		int a = read(x), b = read(y);
		f[b] = a;
	}
	for (int i=1; i<=n; i++)
		dep[i] = getd(i);
	int depth = 0;
	for (int i=1; i<=n; i++)
		depth = max(depth, dep[i]);
	cout << depth << endl;
	if (depth >= d) cout << "deep xue xi is nb" << endl;
	else cout << "shen du learning is fw" << endl;
	return 0;
}