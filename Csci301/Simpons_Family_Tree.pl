%Name-Ricky Hempel
%Date-10/14/15
%Description-A prolog program for the simpson's family tree.


%Facts:

%Facts for all the males in the family tree.
male(orville_simpson).
male(clancy_bouvier).
male(abraham_simpson).
male(homer_simpson).
male(bart_simpson).

%Facts for all the females in the family tree.
female(yuma_simpson).
female(jackie_bouvier).
female(mona_simpson).
female(patty_bouvier).
female(selma_bouvier).
female(marge_simpson).
female(lisa_simpson).
female(maggy_simpson).

% Facts for all the parent child relationships, divided up into families
% to be easier to read.

%Orville and Yuma Simpson family.
parent(orville_simpson,abraham_simpson).
parent(yuma_simpson,abraham_simpson).

%Clancy and Jackie Bouvier family.
parent(clancy_bouvier,patty_bouvier).
parent(clancy_bouvier,selma_bouvier).
parent(clancy_bouvier,marge_simpson).
parent(jackie_bouvier,patty_bouvier).
parent(jackie_bouvier,selma_bouvier).
parent(jackie_bouvier,marge_simpson).

%Abraham and Mona Simpson famliy.
parent(abraham_simpson,homer_simpson).
parent(mona_simpson,homer_simpson).

%Homer and Marge Simpson family.
parent(homer_simpson,bart_simpson).
parent(homer_simpson,lisa_simpson).
parent(homer_simpson,maggy_simpson).
parent(marge_simpson,bart_simpson).
parent(marge_simpson,lisa_simpson).
parent(marge_simpson,maggy_simpson).


%Rules:

% Rule for being married: A married couple has to have a male, a female,
% and have at least one child together.

married(Husband,Wife) :- parent(Husband,Child),parent(Wife,Child), male(Husband),female(Wife).


% Rule for being a father: To a be a father one has to be a parnet of
% a child and be a male.

father(Father,Child) :- parent(Father,Child), male(Father).

% Rule for being a mother: To be a mother one has to be a parnet of a
% child and a female.

mother(Mother,Child) :- parent(Mother,Child), female(Mother).

% Rule for being a daughter: To be a daughter one has to have parnets
% and be a female.

daughter(Daughter,Parent) :- parent(Parent,Daughter), female(Daughter).

% Rule for being a son: To be a son one has to have parnets and be a
% male.

son(Son,Parent) :- parent(Parent,Son), male(Son).

% Rule for being a sibling: To be a sibling one needs to have the same
% parnets and not equal your other sibling.

sibling(Sibling1, Sibling2) :- father(Father,Sibling1), father(Father,Sibling2),
	mother(Mother, Sibling1), mother(Mother, Sibling2), Sibling1 \== Sibling2.

% Rule for being a brother: To be a brother one has to be a sibling and
% be a male.

brother(Brother,Sibling) :- sibling(Brother,Sibling), male(Brother).

% Rule for being a sister: To be a sister one has to be a sibling and be
% a female.

sister(Sister,Sibling) :- sibling(Sister,Sibling), female(Sister).









