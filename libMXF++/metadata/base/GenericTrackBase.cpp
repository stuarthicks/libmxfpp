/*
 * Copyright (C) 2008, British Broadcasting Corporation
 * All Rights Reserved.
 *
 * Author: Philip de Nier
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the British Broadcasting Corporation nor the names
 *       of its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <memory>

#include <libMXF++/MXF.h>


using namespace std;
using namespace mxfpp;


const mxfKey GenericTrackBase::setKey = MXF_SET_K(GenericTrack);


GenericTrackBase::GenericTrackBase(HeaderMetadata *headerMetadata)
: InterchangeObject(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

GenericTrackBase::GenericTrackBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: InterchangeObject(headerMetadata, cMetadataSet)
{}

GenericTrackBase::~GenericTrackBase()
{}


bool GenericTrackBase::haveTrackID() const
{
    return haveItem(&MXF_ITEM_K(GenericTrack, TrackID));
}

uint32_t GenericTrackBase::getTrackID() const
{
    return getUInt32Item(&MXF_ITEM_K(GenericTrack, TrackID));
}

uint32_t GenericTrackBase::getTrackNumber() const
{
    return getUInt32Item(&MXF_ITEM_K(GenericTrack, TrackNumber));
}

bool GenericTrackBase::haveTrackName() const
{
    return haveItem(&MXF_ITEM_K(GenericTrack, TrackName));
}

std::string GenericTrackBase::getTrackName() const
{
    return getStringItem(&MXF_ITEM_K(GenericTrack, TrackName));
}

StructuralComponent* GenericTrackBase::getSequence() const
{
    unique_ptr<MetadataSet> obj(getStrongRefItem(&MXF_ITEM_K(GenericTrack, Sequence)));
    MXFPP_CHECK(dynamic_cast<StructuralComponent*>(obj.get()) != 0);
    return dynamic_cast<StructuralComponent*>(obj.release());
}

void GenericTrackBase::setTrackID(uint32_t value)
{
    setUInt32Item(&MXF_ITEM_K(GenericTrack, TrackID), value);
}

void GenericTrackBase::setTrackNumber(uint32_t value)
{
    setUInt32Item(&MXF_ITEM_K(GenericTrack, TrackNumber), value);
}

void GenericTrackBase::setTrackName(std::string value)
{
    setStringItem(&MXF_ITEM_K(GenericTrack, TrackName), value);
}

void GenericTrackBase::setSequence(StructuralComponent *value)
{
    setStrongRefItem(&MXF_ITEM_K(GenericTrack, Sequence), value);
}

