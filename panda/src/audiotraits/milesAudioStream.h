// Filename: milesAudioStream.h
// Created by:  drose (26Jul07)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#ifndef MILESAUDIOSTREAM_H
#define MILESAUDIOSTREAM_H

#include "pandabase.h"
#ifdef HAVE_RAD_MSS //[

#include "milesAudioSound.h"
#include "milesAudioManager.h"
#include "mss.h"

////////////////////////////////////////////////////////////////////
//       Class : MilesAudioStream
// Description : This represents a sound file played by the Miles
//               Sound System, similar to MilesAudioSample, except
//               that it is streamed from disk instead of preloaded
//               into memory.
////////////////////////////////////////////////////////////////////
class EXPCL_MILES_AUDIO MilesAudioStream : public MilesAudioSound {
private:
  MilesAudioStream(MilesAudioManager *manager, const string &file_name,
                   const Filename &path);

public:
  virtual ~MilesAudioStream();
  
  virtual void play();
  virtual void stop();
  
  virtual void set_time(float time=0.0f);
  virtual float get_time() const;
  
  virtual void set_volume(float volume=1.0f);
  virtual void set_balance(float balance_right=0.0f);
  virtual void set_play_rate(float play_rate=1.0f);
  
  virtual float length() const;

  virtual AudioSound::SoundStatus status() const;

  virtual void cleanup();

private:
  Filename _path;
  HSTREAM _stream;
  S32 _original_playback_rate;
  mutable float _length;
  mutable bool _got_length;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    MilesAudioSound::init_type();
    register_type(_type_handle, "MilesAudioStream",
                  MilesAudioSound::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;

  friend class MilesAudioManager;
};

#include "milesAudioStream.I"

#endif //]

#endif
