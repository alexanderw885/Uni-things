Goal: sequence DNA quickly
Method: break reads into small, fixed-length tokens

### Terminology
- Kbp: kilo-base-pair, 1000 pairs in a double-stranded DNA
- Mbp: mega-base-pair, 1 million base pairs
- Gbp: giga-base-pair, 1 billion base pairs

- mdBG: minimizer-space de Bruijn graph
	Instead of storing single nucleotides as tokens in a de Bruijn graph, stores short sequences of nucleotides, called minimizers
- minimizer space
	Using minimizers, as in the mdBG, instead of nucleotides
	The list of minimizers is a list of occurrences of a small, predetermined set of k-mers
- k-min-mer
	an ordered list of k minimizers
- base space
	working k-mers/nucleotides, instead of minimizers

- pangenome graph
	A graph that represents multiple genomes at once


### Method
- convert each read into an ordered sequence of its minimizers
- construct the minimizer de Bruijn graph
- simplify the graph, and store it in this state
- convert back into base-space
- get contigs



### Questions
- How do these short sequences of nucleotides, minimizers, differ from k-mers?
	Minimizers are a subset of k-mers. 3-mers, for example, would be all possible combinations of 3 nucleotides. Minimizers would be some % of all these  3-mers
- how do we construct these minimizers?
	They're just K-mers
- minimizers are a small set of k-mers, but not all of them? This sounds lossy, how do we convert back?
	From my understanding so far, here's the method:
	1. We get our set of reads. These are large
	2. From these reads, we get our set of minimizers. In the paper's example, they just use AC, AT, and AG. 
		We now group these minimizers into lists of length k. This is just like a k-mer, but instead of k nucleotides, it's k minimizers. These are called k-min-mers
	3. Using these k-min-mers, we construct the de Bruijn graph. Since it's in minimizer space, this graph is an mdBG
	4. This mdBG can be simplified in all the same ways as a regular de Bruijn graph.
- How do we choose which minimizers to use?
	At first, it seems to be random? We choose some set of k-mers to use as minimizers based on % of k-mers we want to use, then I think we clean up/prune down this set?
	density ($\sigma$): the percent of k-mers to use as minimizers
	K-min-mer recovery ($k$): length of each k-min-mer

- What is POA?
- How do we convert the simplified mdBG into base space? it sounds like a lossy process