create table marque (
	id				serial primary key,
	marque			varchar(30) not null
);

create table model (
	id				serial primary key,
	model			varchar(70) not null,
	marque_id		int not null references marque(id)
);

create table produit (
	pr_cd_pr		bigserial primary key,
	pr_desi			varchar(100) not null,
	pr_stre			int not null default 0,
	pr_douane		varchar(14) not null default 0,
	pr_prac			numeric(8, 2) not null default 0,
	pr_deg			int not null default 0,
	pr_pdn			int not null default 0,
	pr_four			int not null default 0,
	pr_refour		varchar(40) not null,
	pr_codebarre	bigint,
	pr_prix			numeric(8, 2) not null,
	pr_pack			int not null,
	marque_id		int not null references model(id)
);

--PGSql: il faut commit le DDL 
commit;

create view v_produit as
	select
		pr_desi
	from produit
		natural join model
		natural join marque;