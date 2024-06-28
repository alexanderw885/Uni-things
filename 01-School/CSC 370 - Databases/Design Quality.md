improve the quality of a conceptual schema and objectively argue merits of the improvements

What would you expect of a good design?

- Completeness: represents all features of the application domain
- Correctness: properly uses concepts of the ER model, syntactically correct
- Minimality: everything in the schema is only represented once, no element can be deleted without violating requirements or losing information
- Expressiveness: represents requirements in natural, understandable way
- Readability: looks good
- Self-Explanation: annotations to explain schema
- Extensibility: easy to adapt to changing requirements
- Normality: is normalised

### Schema Transformations
produce a new schema S2 out of schema S1
there's two types:
- Information-preserving
- Information-changing
	- Augmenting: more information included than in input schema
	- Reducing: less information than in input schema
	- Incomparable: otherwise

Generally use augmenting transformations to expand scope
reducing transformations to remove unnecessary information
information-preserving to increase readability