conceptual design - what should be in database
logical design - how it maps onto relational data model
physical design - implementing schema correctly

## Conceptual design
Defines what should be in the database, independent of the logical model
broad understanding at a quick glance

a miminal design is one with no repeating

#### Example: what should a user rating tracker system be able to do?

assign ratings to movies
track number of ratings per movie
allow users to rate movies
allow users to delete their ratings
allow users to search for movies
recommend movies based on rating history
show ratings of a given movie
show ratings of selected user
Admin fields to update/correct errors
remove bot reviews


##### What data elements do we need for those?
Movie
ratings
user with ids
who is admin
movie metadata


## Entity-Relationship Diagrams (ERDs)
visual way to represent databases

#### Entity sets
represented by rectangles, similar to a class in an OOP language

#### Attributes
connected to an entity, circle/oval shape
like a 'member variable'

![[Pasted image 20240515130147.png]]
#### Identifiers
attributes are identifiers if they are unique
ex. no two students have the same v-number, they are identifiers
identifier attributes are __underlined___

#### Attribute or entity set?
if somethings has no attributes, it should be an attribute
if there's a specific/finite list of possibilities, it should be set as an entity set
ex. cities, you might want users to pick from a list of predetermined cities.

#### Relationships
Diamond shape
connects two or more entities, explains how they're related to each other
relationships can also have attributes
![[Pasted image 20240515131618.png]]
since students have multiple classes, their grade isn't an attribute on the student
instead, it's an attribute of the relation between the student and the class

### Continuing our example:
Movie
ratings
user with ids
who is admin
movie metadata

Movies is entity set, finite list of movies
- movie_id IDENTIFIER
- raumber of ratings
- title
- release year

Rating is the relationship between user and ratings


user has attributes, make entity set
- admin status is attribute
- user_id IDENTIFIER


