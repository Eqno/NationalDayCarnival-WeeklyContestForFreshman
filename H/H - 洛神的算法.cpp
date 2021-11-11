/*
时间限制：
	1s。
空间限制：
	256m。
题目：
	H - 洛神的算法。
描述：
	东君：“嗯？你为什么认为深度学习不够自由？”
	林浔在纸上画了一个方框，解释：“首先还是它的黑箱性质，神经网络的很多地方都不能被解释。比如说图像识别，Google的算法曾经将黑人错误识别为黑猩猩，但我们不知道它为什么出现这种错误，因为很难解释它做出决策的全部过程。”

	“很多研究都在尝试解决这个问题。”东君道。
	“其实这也不是主要的原因。”林浔道。
	他看见男神微微挑了挑眉。

	“在大数据的基础上，使用模拟生物神经网络的方式，做出结果……它的思考来源、过程和结果，都来自原本的数据流。”林浔举了一个例子：“比如，在社会歧视女性的情况下，这社会所产生的数据也倾向这一点，这个人工智能根据数据做出的决定也会是歧视女性的。”
	说完这句，看到东君眼中认真在听的神色，他微微放松了一些：“人工智能的本质并不是智能，仍然是统计。神经网络做出的决策，无法脱离原有数据库，所以它不自由。黑箱问题可以解决，但这个问题是不能被解决的。”

	东君道：“但是已经能够满足社会需求。”
	“是的，但……”林浔直视东君的眼睛，认真道：“但我可以做得更好。”
	根据以往的经验，说到这里的时候，对面的人就会摇头笑而不语，认为他是夸夸其谈的蠢货了。毕竟这个时代的人们热爱无所不能的神经网络，如同相信真理。
	但意外地，东君没有这样。
	他道：“讲你的思路。”

	“谢谢您。”他略微垂了眼睫，在白纸上写下一串单词：“首先假设个体的人是趋利避害的，然后可以初步建立一个模型。”
	他的算法不是很好解释，并且听起来和神经网络的作用并无太大差别。
	现实世界是非线性的，用模糊数学可以对现实世界的无规律信息进行评价，分形与混沌则可以进一步处理更为复杂的问题。
	至少，他认为，在一定程度上，“洛神”是清晰、独立并且自由的。

	“最后，‘洛神’用到了著名的 abc 猜想。它已在许多年前，被望月新一严谨证明。我们知道，任何正整数都可以被分解成若干个质因数相乘，例如：5、3、2 是 60 的质因数，60 = 5×3×2×2，abc 猜想可以简单解释为，有 a、b、c 三个互质整数，其中 c=a+b，猜想认为，这三个数的质因数相乘的结果比 c 小的 a、b、c 组合是有限的。”
	“但我们不会用到定理的全部，而是只需要知道，对于一个正整数 c，是否存在正整数 a、b，使得 a+b=c，且 P(abc) < c。”
	“其中，P(x) 为 x 的所有质因数——不重复的质因数，相乘所得的值。如：P(20) = 2×5 = 10。”
	……
	也不知讲了多久，林浔终于讲清了核心算法，整个人有点虚脱。
	似乎恰到好处地，男神推了一杯冰水到他面前。

	男神什么时候去倒的水？还是阮助理来过了？
	林浔发现自己方才可能讲得过于聚精会神，什么都没有察觉到。

	他喝了一口玻璃杯里的水，水里有冷冽的寒气，像东君身上的气息。

	东君正在从头翻看那七张写满了的草稿纸。
	林浔有点歉然：“不好意思，写得有点乱。”
	而且用了很多前沿的数学，王安全和赵架构全都止步在了这里。
	“没关系，”东君翻了下一页，淡淡道：“我看得懂。”

	下午的阳光并不刺眼，温和地落在房间内，东君的睫毛因此被浸入了金色的微光。他的目光落在纸张上，很显然，是认真在阅读的神色。
	三年来，林浔感觉洛神第一次有了希望。
	至少有一个能看懂它的人，在认真看它了。
	——而且这人还是男神。

	聪明的你一定对林浔所说的“洛神”最后一个算法，即 abc 猜想的部分应用很感兴趣，那么如果给你一个正整数 c，你能找出正整数 a、b，使得 a+b=c，且 P(abc) < c 吗？
输入：
	输入包含一行，为一个正整数 c。
	保证 1 <= c <= 1e18。
输出：
	输出包含一行。
	若存在正整数 a、b，使得 a+b=c，且 P(abc) < c，则输出“Yes”，否则输出“No”。
	输出不包含引号。
样例：
	input:
		20
	output:
		Yes
	input:
		30
	output:
		No
*/

#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1e6+10;
bool judgeSqrt(long long n)
{
	long long sq = sqrt(n);
	if (sq * sq == n) return true;
	return false;
}
int main()
{
	long long c;
	cin >> c;
	bool f = false;
	for (long long i=1; i<=MAXN && i<c; i++)
		if (c % i == 0)
		{
			c /= i;
			if (i!=1 && c%i==0 || judgeSqrt(c))
			{
				f = true;
				break;
			}
		}
	if (f) puts("yes");
	else puts("no");
	return 0;
}
