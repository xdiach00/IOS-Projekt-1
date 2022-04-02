POUŽITÍ: corona [-h] [FILTERS] [COMMAND] [LOG [LOG2 [...]]
    Corona - analyzátor záznamů osob s prokázanou nákazou koronavirem způsobujícím onemocnění COVID-19
-    -h — vypíše nápovědu s krátkým popisem každého příkazu a přepínače
 
FILTERS:
-     -a DATETIME — after: jsou uvažovány pouze záznamy PO tomto datu (včetně tohoto data). DATETIME je formátu YYYY-MM-DD
-     -b DATETIME — before: jsou uvažovány pouze záznamy PŘED tímto datem (včetně tohoto data)
-     -g GENDER — jsou uvažovány pouze záznamy nakažených osob daného pohlaví. GENDER může být M (muži) nebo Z (ženy)
-     -s u příkazů gender, age, daily, monthly, yearly, countries, districts a regions vypisuje data ne číselně, ale graficky v podobě histogramů
COMMAND:
-      infected — spočítá počet nakažených
-      merge — sloučí několik souborů se záznamy do jednoho, zachovávající původní pořadí (hlavička bude ve výstupu jen jednou)
-      gender — vypíše počet nakažených pro jednotlivá pohlaví
-      age — vypíše statistiku počtu nakažených osob dle věku
-      daily — vypíše statistiku nakažených osob pro jednotlivé dny
-      monthly — vypíše statistiku nakažených osob pro jednotlivé měsíce
-      yearly — vypíše statistiku nakažených osob pro jednotlivé roky
-      countries — vypíše statistiku nakažených osob pro jednotlivé země nákazy
-      districts — vypíše statistiku nakažených osob pro jednotlivé okresy
-      regions — vypíše statistiku nakažených osob pro jednotlivé kraje
      
Vstupni data:
  id,datum,vek,pohlavi,kraj_nuts_kod,okres_lau_kod,nakaza_v_zahranici,nakaza_zeme_csu_kod,reportovano_khs
  
  
Supports: csv, gz, bz2 and standart input 
