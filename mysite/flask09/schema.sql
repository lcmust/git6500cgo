drop table if exists entries;
create table entries (
	id integer primary key autoincrement,
	title string not null,
	text string not null,
	create_datetime date default datetime,
	modifi_datetime date,
	auth string
);
