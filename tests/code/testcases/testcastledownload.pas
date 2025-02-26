﻿// -*- compile-command: "./test_single_testcase.sh TTestDownload" -*-
{
  Copyright 2020-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Test CastleDownload unit. }
unit TestCastleDownload;

interface

uses
  Classes, SysUtils, {$ifndef CASTLE_TESTER}FpcUnit, TestUtils, TestRegistry,
  CastleTestCase{$else}CastleTester{$endif};

type
  TTestDownload = class(TCastleTestCase)
  published
    procedure TestLocalChars;
    procedure TestTextReader;
  end;

implementation

uses CastleDownload, CastleClassUtils, CastleVectors, CastleStringUtils;

procedure TTestDownload.TestLocalChars;

  procedure TestReading(const URL: String);
  var
    Stream: TStream;
    S: String;
  begin
    Stream := Download(URL);
    try
      S := StreamToString(Stream);
      AssertEquals('Testing.', Trim(S));
    finally FreeAndNil(Stream) end;
  end;

begin
  TestReading('castle-data:/local_chars/ascii_name.txt');
  TestReading('castle-data:/local_chars/name with Polish chars ćma źrebak żmija wąż królik.txt');
  TestReading('castle-data:/local_chars/name with Chinese chars 样例中文文本.txt');
  TestReading('castle-data:/local_chars/样例中文文本/name with Chinese chars 样例中文文本.txt');
end;

procedure TTestDownload.TestTextReader;

{ Testcase based on example from
  https://forum.castle-engine.io/t/setup-files-and-working-with-them/630/4
}

var
  T: TTextReader;
  X, Y, Z: Single;
  V: TVector3;
begin
  { using ReadSingle }
  T := TTextReader.Create('castle-data:/test_text_reader.txt');
  try
    X := T.ReadSingle;
    Y := T.ReadSingle;
    Z := T.ReadSingle;
    AssertSameValue(1, X);
    AssertSameValue(2, Y);
    AssertSameValue(3, Z);

    X := T.ReadSingle;
    Y := T.ReadSingle;
    Z := T.ReadSingle;
    AssertSameValue(4, X);
    AssertSameValue(5, Y);
    AssertSameValue(6, Z);

    X := T.ReadSingle;
    Y := T.ReadSingle;
    Z := T.ReadSingle;
    AssertSameValue(7, X);
    AssertSameValue(8, Y);
    AssertSameValue(9, Z);
  finally FreeAndNil(T) end;

  { alternative version using ReadVector3 }
  T := TTextReader.Create('castle-data:/test_text_reader.txt');
  try
    V := T.ReadVector3;
    AssertVectorEquals(Vector3(1, 2, 3), V);
    V := T.ReadVector3;
    AssertVectorEquals(Vector3(4, 5, 6), V);
    V := T.ReadVector3;
    AssertVectorEquals(Vector3(7, 8, 9), V);
  finally FreeAndNil(T) end;

  { alternative version using Readln + Vector3FromStr }
  T := TTextReader.Create('castle-data:/test_text_reader.txt');
  try
    V := Vector3FromStr(T.Readln);
    AssertVectorEquals(Vector3(1, 2, 3), V);
    V := Vector3FromStr(T.Readln);
    AssertVectorEquals(Vector3(4, 5, 6), V);
    V := Vector3FromStr(T.Readln);
    AssertVectorEquals(Vector3(7, 8, 9), V);
  finally FreeAndNil(T) end;

  { alternative version using Readln + DeFormat }
  T := TTextReader.Create('castle-data:/test_text_reader.txt');
  try
    DeFormat(T.Readln, '%.single. %.single. %.single.', [@X, @Y, @Z]);
    AssertSameValue(1, X);
    AssertSameValue(2, Y);
    AssertSameValue(3, Z);

    DeFormat(T.Readln, '%.single. %.single. %.single.', [@X, @Y, @Z]);
    AssertSameValue(4, X);
    AssertSameValue(5, Y);
    AssertSameValue(6, Z);

    DeFormat(T.Readln, '%.single. %.single. %.single.', [@X, @Y, @Z]);
    AssertSameValue(7, X);
    AssertSameValue(8, Y);
    AssertSameValue(9, Z);
  finally FreeAndNil(T) end;
end;

initialization
  RegisterTest(TTestDownload);
end.
